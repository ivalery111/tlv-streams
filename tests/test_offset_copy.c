#include <stdio.h>

#include "stream.h"
#include "utils.h"

static void test_offset_copy() {
  stream_t *stream = NULL;

  stream_init_size(&stream, 8);

  const char *data = "zZ";

  /* Write the 'data' to the stream on offset 5 */
  stream_insert_offset(stream, data, strlen(data), 5);

  assert(0 == memcmp(stream->buffer, "\0", 4));
  assert(0 == memcmp(stream->buffer + 5, "z", 1));
  assert(0 == memcmp(stream->buffer + 6, "Z", 1));
  assert(0 == memcmp(stream->buffer + 7, "\0", 1));
}

int main(void) {
  test_offset_copy();

  return 0;
}
