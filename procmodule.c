#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk(KERN_INFO "Hello tiny kitty :)\n");

	char *argv[] = { "/bin/sh", "-c", "echo `whoami` > /root/whoami_from_kernel", NULL };
        static char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };

        call_usermodehelper( argv[0], argv, envp, UMH_WAIT_PROC);


	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Exit.\n");
}
