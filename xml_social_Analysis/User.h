#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>

class User {
public:
    std::string user_name;
    int user_id = 0;
    int num_followers = 0, num_following = 0;

    static std::multimap<int, int> id_to_following;
    static std::multimap<int, int> following_count_to_id;
    static std::multimap<int, int> follower_count_to_id;
    static std::multimap<int, int> connection_count_to_id;

    std::vector<int> follower_ids;
    std::vector<int> following_ids;
    std::vector<std::string> user_posts;

    ~User() {}
    void display();
    void add_follower(int follower_id);
    static void add_following(std::map<int, User>& id_to_user);
    static void finish_maps(std::map<int, User> id_to_user);
    static int most_followers(std::map<int, User> id_to_user);
    static void most_active(std::map<int, User> id_to_user);
    static std::map<int, std::string> suggest(std::map<int, User> id_to_user, int id);
    static std::map<int, std::string> mutual(std::map<int, User> id_to_user, std::vector<int> ids);

};

#endif // USER_H
