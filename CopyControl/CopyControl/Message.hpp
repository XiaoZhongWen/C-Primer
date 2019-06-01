//
//  Message.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Message_hpp
#define Message_hpp

#include <stdio.h>
#include <string>
#include <set>

class Folder;
class Message {
    friend class Folder;
public:
    explicit Message(const std::string &str = ""): content(str) {};
    Message(const Message &msg);
    Message(Message &&) noexcept;
    Message& operator=(const Message &msg);
    Message& operator=(Message &&) noexcept;
    ~Message();
    
    void addFolder(Folder *);
    void remFolder(Folder *);
    void save(Folder &);
    void remove(Folder &);
    void move_Folders(Message &);
private:
    std::string content;
    std::set<Folder *> folders;
    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

#endif /* Message_hpp */
