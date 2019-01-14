#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <errno.h>
#include <stdio.h>

/*
#define DPRINTF(x) do {\
                int save_errno = errno; \
                if ((statp->options & RES_DEBUG) != 0U) res_dprintf x; \
                    errno = save_errno; \
                } while (0)

*/
#define DPRINTF(x) _exit(39)

int *__errno_location(void);

//#undef _IO_getc


//#undef stdout
//extern FILE* __stdoutp;
//extern FILE* stdout __attribute__((weak));
//static FILE* __stdoutp1;
//extern FILE* stdout __attribute__((weak, alias("__stdoutp")));

//static FILE* stdout = __stdoutp;

//#pragma weak stdout = __stdoutp

#ifdef stdin
#undef stdin
#undef stdout
#undef stderr

FILE *stdin;
FILE *stdout;
FILE *stderr;
#endif

static void __attribute__((constructor))
oci8stub_init(void)
{
//        DPRINTF(("%s\n", __FUNCTION__));
//        #ifdef stdin
        stdin = __stdinp;
        stdout = __stdoutp;
        stderr = __stderrp;
//        #endif
//	printf("oci8stub_init - %s\n",__FUNCTION__);
}
                                

int
_IO_getc (FILE *fp)
{
  return getc(fp);
}

int
_IO_putc (int c, FILE *fp)
{
  return putc(c,fp);
}

off_t ftello64(FILE *fp)
{
    return ftello(fp);
}

off_t
lseek64(int fd,off_t offset,int whence)
{
    return lseek(fd,offset,whence);
}

int
open64(const char *file,int oflag)
{
    return open(file,oflag);
}

void*
mmap64 (void *addr, size_t len, int prot, int flags, int fd, off_t offsett)
{
    return mmap(addr, len, prot, flags, fd, offsett);
}

int
fseeko64 (FILE *stream, off_t offset, int whence)
{
    return fseeko(stream, offset,whence);
}
int
__sigsetjmp (sigjmp_buf env, int savemask)
{
    return sigsetjmp (env, savemask);
}


void* __h_errno_location()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

int *
__errno_location(void)
{
    return &errno;
}

void* __ctype_toupper_loc()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

void* __ctype_tolower_loc()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}
/*
void* __ctype_b_loc()
{
    printf("stub - %s\n", __FUNCTION__);
//    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}
*/
void* __assert_fail()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

void* __xstat64()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

void* __finite()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

void* __lxstat64()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

void* __fxstat64()
{
    DPRINTF(("stub - %s\n", __FUNCTION__));
    return NULL;
}

int __xstat(int ver, const char *path, struct stat *sb)
{

//    DPRINTF(("stub - %s\n", __FUNCTION__));
//    printf("stub - %s - ver = %d path=%s %Xz\n", __FUNCTION__,ver,path,sb);
    return _stat(path, sb);
}

int __fxstat(int ver, int fd, struct stat *sb)
{
    //DPRINTF(("stub - %s\n", __FUNCTION__));
//    printf("stub - %s - ver = %d fd=%d %Xz\n", __FUNCTION__,ver,fd,sb);
    return _fstat(fd, sb);
}

