#include "database.h"

#include <boost/chrono.hpp>
#include <boost/make_shared.hpp>

#include "documents.h"

Database::Database(const char* name) : name_(name), instanceStartTime_(Now()),
    committedUpdateSeq_(0), updateSeq_(0), purgeSeq_(0), dataSize_(0), diskSize_(0),
    docDelCount_(0) {
}

database_ptr Database::Create(const char* name) {
    database_ptr ptr(new Database(name));
    if (!!ptr) {
        ptr->docs_ = Documents::Create(ptr);
    }
    return ptr;
}

unsigned long Database::Now() {
    auto now = boost::chrono::system_clock::now().time_since_epoch();
    return boost::chrono::duration_cast<boost::chrono::microseconds>(now).count();
}

unsigned long Database::DocCount() { 
    return docs_->getCount(); 
}

document_ptr Database::GetDocument(const char* id) {
    return docs_->GetDocument(id);
}

document_ptr Database::DeleteDocument(const char* id, const char* rev) {
    return docs_->DeleteDocument(id, rev);
}

document_ptr Database::SetDocument(const char* id, script_object_ptr obj) {
    return docs_->SetDocument(id, obj);
}

document_array Database::GetDocuments() {
    return docs_->GetDocuments();
}