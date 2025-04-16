#include "Song.hpp"
#include "Playlist.hpp"
#include <iostream>

Playlist::Playlist(string playlistName) : name(playlistName) {}

const string &Playlist::getName() const {
    return name;
}

const vector<Song> &Playlist::getSongs() const {
    return songs;
}

void Playlist::addSong(const Song &song) {
    for (const auto &s : songs) {
        if (s == song) {
            return;
        }
    }
    songs.push_back(song);
}

bool Playlist::removeSong(const Song &songToRemove) {
    for (auto it = songs.begin(); it != songs.end(); ++it) {
        if (*it == songToRemove) {
            songs.erase(it);
            return true;
        }
    }
    return false;
}

void Playlist::removeSongByIndex(size_t index) {
    try
    {
        if (index < 0 || index >= songs.size()) {
            throw out_of_range("Index out of range");
        }
        songs.erase(songs.begin() + index);
    }
    catch(const out_of_range &e)
    {
        std::cout << e.what() << '\n';
    }
    
}

size_t Playlist::numberOfSongs() const {
    return songs.size();
}

ostream &operator<< (ostream &os, const Playlist &pl) {
    os << "Playlist: " << pl.getName() << " (" << pl.numberOfSongs() << " lagu)" << endl;
    for (size_t i = 0; i < pl.numberOfSongs(); ++i) {
        os << i + 1 << ". " << pl.getSongs()[i] << endl;
    }
    return os;
}