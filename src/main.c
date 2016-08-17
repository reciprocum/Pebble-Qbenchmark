#include <Config.h>
#include <pebble.h>
#include <Q.h>

Window    *my_window ;
TextLayer *text_layer ;

#define INNER_LOOP_COUNT  1000000000
#define OUTER_LOOP_COUNT  1000000


void
run_benchmark( void )
{
  // native floats.
  float f_pi  = 3.14159265358979323846264338323f ;
  float f_acc = 0.0f ;

  static uint16_t beforeMs, afterMs ;
  time_ms( NULL, &beforeMs ) ;
  LOGD( "float.beforeMs := %d", beforeMs ) ;
  
  for (int j = 0  ;  j < OUTER_LOOP_COUNT  ;  ++j)
    for (int i = 0  ;  i < INNER_LOOP_COUNT  ;  ++i)
    {
      float f_i   = (float)i ;
      float f_mul = f_i * f_pi ;
            f_acc = f_acc + f_mul ;
    }
  
  time_ms( NULL, &afterMs ) ;
  LOGD( "float.afterMs := %d", afterMs ) ;
  
  LOGD( "float.elapsed (count = %d) := %d", INNER_LOOP_COUNT, (int)(afterMs - beforeMs) ) ;
  
  
  // Q15.16 floats.
  Q q_pi  = Q_PI ;
  Q q_acc = Q_0 ;

  time_ms( NULL, &beforeMs ) ;
  LOGD( "Q.beforeMs := %d", beforeMs ) ;

  for (int j = 0  ;  j < OUTER_LOOP_COUNT  ;  ++j)
    for (int i = 0  ;  i < INNER_LOOP_COUNT  ;  ++i)
    {
      Q q_i   = Q_make(i) ;
      Q q_mul = Q_mul( q_i, q_pi ) ;
        q_acc = Q_add( q_acc, q_mul ) ;
    }

  time_ms( NULL, &afterMs ) ;
  LOGD( "Q.afterMs := %d", afterMs ) ;

  LOGD( "Q.elapsed (count = %d) := %d", INNER_LOOP_COUNT, (int)(afterMs - beforeMs) ) ;
}


void
handle_init(void)
{
  my_window = window_create();

  text_layer = text_layer_create(GRect(0, 0, 144, 20));
  window_stack_push(my_window, true);
}

void
handle_deinit(void)
{
  text_layer_destroy(text_layer) ;
  window_destroy(my_window) ;
}

int
main( void )
{
  handle_init( ) ;
  run_benchmark( ) ;
  app_event_loop( ) ;
  handle_deinit( ) ;
}