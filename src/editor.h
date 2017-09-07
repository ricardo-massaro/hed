/* editor.h */

#ifndef EDITOR_H_FILE
#define EDITOR_H_FILE

#include "hed.h"
#include "screen.h"

enum hed_edit_mode {
  HED_MODE_DEFAULT,
  HED_MODE_READ_STRING,
  HED_MODE_READ_YESNO,
};

struct hed_editor {
  char *filename;
  uint8_t *data;
  size_t data_len;
  bool modified;
  bool quit;
  
  bool msg_was_set;
  char cur_msg[256];
  enum hed_edit_mode edit_mode;
  struct hed_screen screen;
};

void hed_init_editor(struct hed_editor *editor);
int hed_read_file(struct hed_editor *editor, const char *filename);
int hed_set_data(struct hed_editor *editor, uint8_t *data, size_t data_len);
int hed_run_editor(struct hed_editor *editor);
int hed_show_msg(struct hed_editor *editor, const char *fmt, ...) HED_PRINTF_FORMAT(2, 3);

#endif /* EDITOR_H_FILE */
