#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;      // Pointer to the dynamically allocated buffer
    size_t length;  // Current length of the string
    size_t capacity; // Current capacity of the buffer
} StringBuilder;

// Initialize the StringBuilder with an initial capacity
void initStringBuilder(StringBuilder *sb, size_t initialCapacity) {
    sb->str = (char *)malloc(initialCapacity);
    if (sb->str == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    sb->length = 0;
    sb->capacity = initialCapacity;
    sb->str[0] = '\0';
}

// Append a string to the StringBuilder
void appendString(StringBuilder *sb, const char *text) {
    size_t textLength = strlen(text);
    if (sb->length + textLength + 1 > sb->capacity) {
        sb->capacity = (sb->length + textLength + 1) * 2;
        sb->str = (char *)realloc(sb->str, sb->capacity);
        if (sb->str == NULL) {
            perror("Failed to reallocate memory");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(sb->str + sb->length, text);
    sb->length += textLength;
}

// Free the memory allocated for the StringBuilder
void freeStringBuilder(StringBuilder *sb) {
    free(sb->str);
    sb->str = NULL;
    sb->length = 0;
    sb->capacity = 0;
}

// Example usage
int main() {
    StringBuilder sb;
    initStringBuilder(&sb, 16);
    appendString(&sb, "Hello");
    appendString(&sb, " ");
    appendString(&sb, "World!");
    printf("%s\n", sb.str); // Outputs: Hello World!
    freeStringBuilder(&sb);
    return 0;
}
