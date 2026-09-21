import os
import random

# Configuration
target_size_mb = 1000  # Change to 1000 for ~1GB
output_filename = f"generated_words/{target_size_mb}MB.txt"

crimefile = open('1000-most-common-portuguese-words.txt', 'r', encoding='utf-8')
words_pool = [line.strip(' ').strip('\n') for line in crimefile]

target_bytes = target_size_mb * 1024 * 1024
bytes_written = 0

print(f"Generating a {target_size_mb}MB text file...")

path = str(os.path.abspath(os.getcwd()))+"\generated_words"
try:
    os.mkdir(path)
except:
    1
with open(output_filename, "w", encoding="utf-8") as f:
    while bytes_written < target_bytes:
        # Generate a line of random words
        line = " ".join(random.choices(words_pool, k=20)) + "\n"
        f.write(line)
        bytes_written += len(line.encode("utf-8"))

print(f"Done! Created '{output_filename}' ({bytes_written / (1024*1024):.2f} MB)")