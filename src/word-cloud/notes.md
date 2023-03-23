# Issues
- Bitset worked well with single bits, but only stored a boolean (single bit)
- Storing the count requires an int, 2 byte short most likely (1 byte limit to 256 and word counts would exceed this)
- Program shows that the max index value of a vector is massive, but program is killed for memory issues I believe.
- With K = 2 to make a truly unique ID, would be 6000000060000000. Fits within the index limits but that x 2 bytes to hold the counts is
- 6.0 x 10^15 even with single byte 5.3 PB
- K = 1  requires 1.74*10^9 would be around 3 gb. 
- Repl killed off at this value. worked fine with 1 billion shorts

# Ideas on how to approach this:

1. MapReduce (Potentially what we were already going to be doing) But could be done with traditional hash table and even CPU only type approach if this data structure  doesn't work with GPU
2. still hash each word, count each hash. Distribute based on hashed range? Pretty sizeable bottle neck but seems present regardless.
3. Not sure what data parallel is, but hashing words and sending update statments to a database? I assume the connections to a DB would be far slower than doing more of the hashtable approach, but does indexing the hash value as a primary key give any advantage? 

