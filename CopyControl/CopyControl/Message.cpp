//
//  Message.cpp
//  CopyControl
//
//  Created by 肖仲文 on 2019/5/23.
//  Copyright © 2019 肖仲文. All rights reserved.
//

#include "Message.hpp"
#include "Folder.hpp"

Message::Message(const Message &msg): content(msg.content), folders(msg.folders) {
    add_to_Folders(*this);
}

Message::Message(Message &&m) noexcept : content(std::move(m.content)) {
    move_Folders(m);
}

Message& Message::operator=(const Message &msg) {
    remove_from_Folders();
    content = msg.content;
    folders = msg.folders;
    add_to_Folders(msg);
    return *this;
}

Message& Message::operator=(Message &&m) noexcept {
    if (this != &m) {
        remove_from_Folders();
        content = std::move(m.content);
        move_Folders(m);
    }
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::move_Folders(Message &m) {
    folders = std::move(m.folders);
    for (auto folder : folders) {
        folder->remMsg(&m);
        folder->addMsg(this);
    }
    m.folders.clear();
}

void Message::addFolder(Folder *f) {
    folders.insert(f);
}

void Message::remFolder(Folder *f) {
    folders.erase(f);
}

void Message::add_to_Folders(const Message &msg) {
    for (auto folder : msg.folders) {
        folder->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for (auto folder : folders) {
        folder->remMsg(this);
    }
}
