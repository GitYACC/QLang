typedef struct DecimalObject {
    // Q visible attrs
    string value;
    //string _in_file;
    //int line;
    //int column;
    Q_size_t size;

    // Q conditional visibility (module requirment: inspect)
    size_t csize;
    string ctype;

    // Q invisible attrs
    list(string) overflow_vals;
    //list(string) lifetime;
    int overflow;

    // object (IntegerObject) static attrs
    string MAX;
    string MIN;

} DecimalObject;