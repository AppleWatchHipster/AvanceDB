#ifndef JSON_STREAM_H
#define	JSON_STREAM_H

#include <sstream>

class JsonStream final {
public:
    JsonStream();
    
    void Append(const char* name, const char* value);
    void Append(const char* name, int value);
    void Append(const char* name, unsigned value);
    void Append(const char* name, uint64_t value);
    void Append(const char* name, int64_t value);
    void Append(const char* name, double value);
    void Append(const char* name, bool value);
    
    std::string Flush();
    
private:
    std::stringstream stream_;
    int count_;
};

#endif	/* JSON_STREAM_H */