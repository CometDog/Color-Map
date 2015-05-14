#include "pebble.h"
#include "libs/pebble-assist.h"
#include "elements.h"

/********************************************************* 
 *                   Aesthetic Updates                   *
 *********************************************************/

static void update_map() {
 
}

static void update_pos() {
	
}

/********************************************************* 
 *                    Click Handlers                     *
 *********************************************************/

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void back_click_handler(ClickRecognizerRef recognizer, void *context) {
	
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_single_click_subscribe(BUTTON_ID_BACK, back_click_handler);
  
  window_single_repeating_click_subscribe(BUTTON_ID_UP, 300, up_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_SELECT, 300, select_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_DOWN, 300, down_click_handler);
  window_single_repeating_click_subscribe(BUTTON_ID_BACK, 300, back_click_handler);
}

/********************************************************* 
 *                      Window Loads                     *
 *********************************************************/

static void main_window_load(Window *window) {
  
  GRect bounds = window_get_bounds(window);

  s_map_layer = layer_create(GRect(0,0,144,144));
  s_selection_layer = layer_create(GRect(0,0,144,144));

  s_selection_label = text_layer_create(GRect(0,144,144,24));
  text_layer_set_colors(s_selection_label, GColorWhite, GColorBlack);
  text_layer_set_text(s_selection_label, "RGB(0,0,0)");
  text_layer_set_text_alignment(s_selection_label, GTextAlignmentCenter);

  layer_add_to_window(s_map_layer, window);
  layer_add_to_window(s_selection_layer, window);
  text_layer_add_to_window(s_selection_label, window);

}

static void main_window_unload(Window *window) {

  layer_destroy_safe(s_map_layer);
  layer_destroy_safe(s_selection_layer);
  
  text_layer_destroy_safe(s_selection_label);
}

/********************************************************* 
 *                  (De)Initialization                   *
 *********************************************************/

static void init() {
  s_main_window = window_create();
  window_handlers(s_main_window, main_window_load, main_window_unload);
  window_stack_push(s_main_window, true);
  window_set_click_config_provider(s_main_window, click_config_provider);

}

static void deinit() {
  window_destroy_safe(s_main_window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}