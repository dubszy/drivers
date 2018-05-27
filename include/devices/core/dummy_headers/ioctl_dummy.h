
#ifndef _IOCTL_DUMMY_H_
#define _IOCTL_DUMMY_H_

#ifndef _IOC_NRBITS
# define _IOC_NRBITS	8
#endif

#ifndef _IOC_TYPEBITS
# define _IOC_TYPEBITS	8
#endif

/*
 * Let any architecture override either of the following before
 * including this file.
 */

#ifndef _IOC_SIZEBITS
# define _IOC_SIZEBITS	14
#endif

#ifndef _IOC_NRSHIFT
# define _IOC_NRSHIFT	0
#endif

#ifndef _IOC_TYPESHIFT
# define _IOC_TYPESHIFT	(_IOC_NRSHIFT+_IOC_NRBITS)
#endif

#ifndef _IOC_NRSHIFT
# define _IOC_SIZESHIFT	(_IOC_TYPESHIFT+_IOC_TYPEBITS)
#endif

#ifndef _IOC_DIRSHIFT
# define _IOC_DIRSHIFT	(_IOC_SIZESHIFT+_IOC_SIZEBITS)
#endif

#ifndef _IOC_WRITE
# define _IOC_WRITE	1U
#endif

#ifndef _IOC_READ
# define _IOC_READ	2U
#endif

#ifndef _IOC
# define _IOC(dir,type,nr,size) \
	(((dir)  << _IOC_DIRSHIFT) | \
	 ((type) << _IOC_TYPESHIFT) | \
	 ((nr)   << _IOC_NRSHIFT) | \
	 ((size) << _IOC_SIZESHIFT))
#endif

#ifndef __KERNEL__
# ifndef _IOC_TYPECHECK
#  define _IOC_TYPECHECK(t) (sizeof(t))
# endif
#endif

#ifndef _IOR
# define _IOR(type,nr,size)	_IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
#endif

#ifndef _IOW
# define _IOW(type,nr,size)	_IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#endif

#endif /* _IOCTL_DUMMY_H_ */
