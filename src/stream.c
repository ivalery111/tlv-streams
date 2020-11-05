#include "stream.h"

void stream_init(stream_t **stream) {
  (*stream) = calloc(1, sizeof(stream_t));
  assert(*stream != NULL);

  (*stream)->buffer = calloc(1, STREAM_DEF_SIZE);
  assert((*stream)->buffer != NULL);

  (*stream)->size = STREAM_DEF_SIZE;

  (*stream)->next = 0;
}

void stream_init_size(stream_t **stream, const size_t stream_size) {
  (*stream) = calloc(1, sizeof(stream_t));
  assert(*stream != NULL);

  (*stream)->buffer = calloc(1, stream_size);
  assert((*stream)->buffer != NULL);

  (*stream)->size = stream_size;

  (*stream)->next = 0;
}

void stream_serialize(stream_t *stream, const char *data,
                      const size_t data_size) {
  size_t available_size = stream->size - stream->next;
  bool is_resize = false;

  while (available_size <= data_size) {
    stream->size = stream->size * 2;
    available_size = stream->size - stream->next;
    is_resize = true;
  }

  if (is_resize == false) {
    memcpy(stream->buffer + stream->next, data, data_size);
    stream->next += data_size;
    return;
  }

  /* resize */
  stream->buffer = realloc(stream->buffer, stream->size);
  assert(stream->buffer != NULL);

  memcpy(stream->buffer + stream->next, data, data_size);
  stream->next += data_size;
}

void stream_deserialize(char *dest, stream_t *stream, size_t size) {
  memcpy(dest, stream->buffer + stream->next, size);

  stream->next += size;
}

void stream_ser_string(stream_t *stream, const char *data,
                       const size_t data_size) {
  stream_serialize(stream, data, data_size);
}

void stream_des_string(char *dest, stream_t *stream, const size_t size) {
  stream_deserialize(dest, stream, size);
}
