//
//  Folder.hpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#ifndef Folder_hpp
#define Folder_hpp

#include <stdio.h>
#include <string>
#include <set>

class Message;
class Folder {
public:
    Folder(const std::string &name): name(name) {};
    
    void addMsg(Message *msg);
    void remMsg(Message *msg);
private:
    std::string name;
    std::set<Message *> messages;
};

#endif /* Folder_hpp */
