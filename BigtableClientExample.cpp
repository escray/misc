// Bigtable: A Distributed Storage System for Structed Data

// Figure 2: Writing to Bigtable
// Open the table
Table *T = OpenOrDie("/bigtable/web/webtable");

// Write a new anchor and delete an old anchor
RowMutation r1(T, "com.cnn.www");
r1.Set("anchor:www.c-span.org", "CNN");
r1.Delete("anchor:www.abc.com");
Operation op;
Apply(&op, &r1);

// Figure 3: Reading from Bigtable
Scanner scanner(T);
ScanStream *stream;
stream = scanner.FetchColumnFamily("anchor");
stream -> SetReturnAllVersions();
scanner.Lookup("com.cnn.www");
for (; !stream->Done(); stream->Next()) {
  printf("%s %s %11d %s\n", 
    scanner.RowName(),
    stream->ColumnName(),
    stream->MicroTimestamp(),
    Stream->Value());
}