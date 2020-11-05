#include <stdio.h>

#include "stream.h"

#define TYPE (15)

static void test_stream_serialize() {
  stream_t *stream = NULL;
  stream_init(&stream);

  /* Type will be 15 */
  const char type = TYPE;
  stream_serialize(stream, &type, sizeof(char));

  const size_t len = 20;
  stream_serialize(stream, (const char *)&len, sizeof(size_t));

  char buffer[20];
  snprintf(buffer, 20, "%s", "qwertyuiopasdfzxcvZ");
  stream_serialize(stream, buffer, 20);

  /**
   * Assume this TLV was sent throught the network...
   *
   * On receiver side
   */

  stream->next = 0;

  char rcv_type = 0;
  stream_deserialize(&rcv_type, stream, sizeof(char));
  assert(rcv_type == TYPE);

  size_t rcv_len = 0;
  stream_deserialize((char *)&rcv_len, stream, sizeof(size_t));
  assert(rcv_len == 20);

  char rcv_buffer[20];
  stream_deserialize(rcv_buffer, stream, 20);
  assert(0 == strcmp(rcv_buffer, "qwertyuiopasdfzxcvZ"));
}

int main(void) {
  test_stream_serialize();

  return 0;
}