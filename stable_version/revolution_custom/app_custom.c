#include "ch.h" // ChibiOS
#include "hal.h" // ChibiOS HAL
#include "mc_interface.h" // Motor control functions
#include "hw.h" // Pin mapping on this hardware
#include "timeout.h" // To reset the timeout
static volatile bool stop_now = true;
static volatile bool is_running = false;
// Example thread
static THD_FUNCTION(example_thread, arg);
static THD_WORKING_AREA(example_thread_wa, 2048); // 2kb stack for this thread

/* 
void app_example_init(void) {

	// Start the example thread
	chThdCreateStatic(example_thread_wa, sizeof(example_thread_wa),
		NORMALPRIO, example_thread, NULL);
}*/

void app_custom_start(void) {
	stop_now = false;
	chThdCreateStatic(example_thread_wa, sizeof(example_thread_wa), NORMALPRIO, example_thread, NULL);
}

void app_custom_stop(void) {
	stop_now = true;
	while (is_running) {
		chThdSleepMilliseconds(1);
	}
}

 
static THD_FUNCTION(example_thread, arg) 
{
	(void)arg;
 
	chRegSetThreadName("APP_EXAMPLE");
        is_running = true;
	for(;;) {

                if (stop_now) 
                {
			is_running = false;
			return;
                }
		
			//mc_interface_set_pid_speed(pot * 10000.0);
			//mc_interface_release_motor();
		
                mc_interface_set_pid_pos(0,8000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);
               
                mc_interface_set_pid_pos(2,8000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);

                mc_interface_set_pid_pos(4,8000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);

                mc_interface_set_pid_pos(8,8000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);
                 
                mc_interface_set_pid_pos(16,8000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);



                mc_interface_set_pid_pos(0,80000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);
               
                mc_interface_set_pid_pos(2,80000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);

                mc_interface_set_pid_pos(4,80000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);

                mc_interface_set_pid_pos(8,80000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);
                 
                mc_interface_set_pid_pos(16,80000);
                
                timeout_reset();
		chThdSleepMilliseconds(900);

		// Reset the timeout
		
                }

}
