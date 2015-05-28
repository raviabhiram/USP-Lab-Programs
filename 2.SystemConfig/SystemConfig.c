#include <stdio.h>
#include <unistd.h>
// this can be found in (vim /usr/include/unistd.h)
int main()
{

	#ifdef _POSIX_JOB_CONTROL
		printf("1.Job control feature is supported\n");
	#else
		printf("1.Job control feature is not supported \n");
	#endif
	
	#ifdef _POSIX_SAVED_IDS
		printf("2.processes have saved the set of user ID's\n");
	#else
		printf("2._POSIX_SAVED_IDS feature is not supported \n");
	#endif	
	
	#ifdef _POSIX_TIMER
		printf("3.Clocks and timer feature is supported\n");
	#else
		printf("3._POSIX_TIMER feature is not supported \n");
	#endif	

	#ifdef _POSIX_THREAD
		printf("4.Pthread feature is supported\n");
	#else
		printf("4.Pthread feature is not supported \n");
	#endif	
	
	#ifdef _POSIX_CHOWN_RESTRICTED
		printf("5. Only the super user can use `chown' to change the owner of a file.  `chown' can only be used to change the group ID of a file to a group of which the calling process is a member.\n");
	#else
		printf("5._POSIX_CHOWN_RESTRICTED feature is not supported \n");
	#endif	

	#ifdef _POSIX_NO_TRUNC
		printf("6. Pathname components longer than NAME_MAX generate an error.\n");
	#else
		printf("6._POSIX_NO_TRUNC feature is not supported \n");
	#endif	

	#ifdef  _POSIX_VDISABLE
		printf("7. no character will have the effect associated with that element.\n");
	#else
		printf("7._POSIX_VDISABLE feature is not supported \n");
	#endif	

	#ifdef _POSIX_SYNC_IO
		printf("8.Synchronous I/O may be performed.\n");
	#else
		printf("8._POSIX_SYNC_IO feature is not supported \n");
	#endif	
	return 0;
}
