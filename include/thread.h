#ifndef __THREAD_H__
#define __THREAD_H__

#include <sys/ppu_thread.h>
#include <sys/sys_types.h>
#include <stdio.h>

void caller(uint64_t arg);

class thread {
public:
	void (*callee)(thread*);
	//sys_ppu_thread_stack_t stack_t;
	sys_ppu_thread_t thread_t;

	thread(void (*exec)(thread*), int size = 0x6000, uint64_t flags = 0) {
		char buffer[27];
		sprintf(buffer, "%p", exec);

		callee = exec;
		if (sys_ppu_thread_create(&thread_t, caller, *(uint64_t*)this, 3070, size, flags, buffer) != CELL_OK)
			printf("there was a problem starting the thread");
	}

	int joinable() {
		int joinable;
		sys_ppu_thread_get_join_state(&joinable);
		return joinable;
	}
	int join() {
		return sys_ppu_thread_join(thread_t, 0);
	}
	void rename(const char *name) {
		sys_ppu_thread_rename(thread_t, name);
	}
	void set_priority(int priority) {
		sys_ppu_thread_set_priority(thread_t, priority);
	}

	uint64_t get_id() {
		__asm("mr %r3, %r2;"
			"blr;");
	}
};

void caller(uint64_t arg) {
	thread *thr = (thread*)&arg;
	//sys_ppu_thread_get_stack_information(&thr->stack_t);
	thr->callee(thr);
	sys_ppu_thread_exit(0);
}

#endif /* __THREAD_H__ */