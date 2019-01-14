LIB=		oci8stub
SRCS=		getc.c C-ctype.c
WARNS=		6

#NO_PIC=		yes
USE_PIC=	yes
#NO_OBJ=		yes
NO_PROFILE=	yes
NO_WERROR=	yes
CFLAGS+=	-fPIC
DEBUG_FLAGS=	-g

#LIBDIR=		${ORACLE_HOME}/lib

#patch:
#	ar r ${ORACLE_HOME}/lib/libclntst8.a ${OBJS}

.include <bsd.lib.mk>

