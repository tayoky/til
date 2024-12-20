#pragma once
void set_tilerr_callback(void (*callback)(const char*,unsigned long,const char *));
void trigger_tilerr(const char* error,unsigned long line,const char *file);