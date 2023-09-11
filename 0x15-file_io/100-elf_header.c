#include"main.h"
/**
 * isElfFile - Checks if a file is an ELF file.
 * @elfIdent: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void isElfFile(unsigned char *elfIdent)
{
    int i;

    for (i = 0; i < 4; i++)
    {
        if (elfIdent[i] != 127 &&
            elfIdent[i] != 'E' &&
            elfIdent[i] != 'L' &&
            elfIdent[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printElfMagic - Prints the magic numbers of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void printElfMagic(unsigned char *elfIdent)
{
    int x;

    printf("  Magic:   ");

    for (x = 0; x < EI_NIDENT; x++)
    {
        printf("%02x", elfIdent[x]);

        if (x == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printElfClass - Prints the class of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF class.
 */
void printElfClass(unsigned char *elfIdent)
{
    printf("  Class:                             ");

    switch (elfIdent[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", elfIdent[EI_CLASS]);
    }
}

/**
 * printElfData - Prints the data of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF class.
 */
void printElfData(unsigned char *elfIdent)
{
    printf("  Data:                              ");

    switch (elfIdent[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", elfIdent[EI_CLASS]);
    }
}

/**
 * printElfVersion - Prints the version of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF version.
 */
void printElfVersion(unsigned char *elfIdent)
{
    printf("  Version:                           %d",
           elfIdent[EI_VERSION]);

    switch (elfIdent[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printElfOsabi - Prints the OS/ABI of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF version.
 */
void printElfOsabi(unsigned char *elfIdent)
{
    printf("  OS/ABI:                            ");

    switch (elfIdent[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", elfIdent[EI_OSABI]);
    }
}

/**
 * printElfAbi - Prints the ABI version of an ELF header.
 * @elfIdent: A pointer to an array containing the ELF ABI version.
 */
void printElfAbi(unsigned char *elfIdent)
{
    printf("  ABI Version:                       %d\n",
           elfIdent[EI_ABIVERSION]);
}

/**
 * printElfType - Prints the type of an ELF header.
 * @elfType: The ELF type.
 * @elfIdent: A pointer to an array containing the ELF class.
 */
void printElfType(unsigned int elfType, unsigned char *elfIdent)
{
    if (elfIdent[EI_DATA] == ELFDATA2MSB)
        elfType >>= 8;

    printf("  Type:                              ");

    switch (elfType)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", elfType);
    }
}

/**
 * printElfEntry - Prints the entry point of an ELF header.
 * @entryPoint: The address of the ELF entry point.
 * @elfIdent: A pointer to an array containing the ELF class.
 */
void printElfEntry(unsigned long int entryPoint, unsigned char *elfIdent)
{
    printf("  Entry point address:               ");

    if (elfIdent[EI_DATA] == ELFDATA2MSB)
    {
        entryPoint = ((entryPoint << 8) & 0xFF00FF00) |
                      ((entryPoint >> 8) & 0xFF00FF);
        entryPoint = (entryPoint << 16) | (entryPoint >> 16);
    }

    if (elfIdent[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)entryPoint);
    else
        printf("%#lx\n", entryPoint);
}

/**
 * closeElfFile - Closes an ELF file.
 * @elfFd: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void closeElfFile(int elfFd)
{
    if (close(elfFd) == -1)
    {
        dprintf(STDERR_FILENO,
            "Error: Can't close fd %d\n", elfFd);
        exit(98);
    }
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *elfHeader;
    int elfFd, bytesRead;

    elfFd = open(argv[1], O_RDONLY);
    if (elfFd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    elfHeader = malloc(sizeof(Elf64_Ehdr));
    if (elfHeader == NULL)
    {
        closeElfFile(elfFd);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }
    bytesRead = read(elfFd, elfHeader, sizeof(Elf64_Ehdr));
    if (bytesRead == -1)
    {
        free(elfHeader);
        closeElfFile(elfFd);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    isElfFile(elfHeader->e_ident);
    printf("ELF Header:\n");
    printElfMagic(elfHeader->e_ident);
    printElfClass(elfHeader->e_ident);
    printElfData(elfHeader->e_ident);
    printElfVersion(elfHeader->e_ident);
    printElfOsabi(elfHeader->e_ident);
    printElfAbi(elfHeader->e_ident);
    printElfType(elfHeader->e_type, elfHeader->e_ident);
    printElfEntry(elfHeader->e_entry, elfHeader->e_ident);

    free(elfHeader);
    closeElfFile(elfFd);
    return (0);
}

