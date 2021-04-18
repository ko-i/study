struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

fn main() {
    let mut user1 = User {
        email: String::from("user1@a.com"),
        username: String::from("user1"),
        active: true,
        sign_in_count: 1,
    };

    println!("{}, {}, {}, {}", user1.email, user1.username, user1.active, user1.sign_in_count);

    user1.email = String::from("user1update@a.com");
    println!("{}, {}, {}, {}", user1.email, user1.username, user1.active, user1.sign_in_count);

    let user2 = build_user(String::from("user2@a.com"), String::from("user2"));
    println!("{}, {}, {}, {}", user2.email, user2.username, user2.active, user2.sign_in_count);

    let user3 = build_user_simple(String::from("user3@a.com"), String::from("user3"));
    println!("{}, {}, {}, {}", user3.email, user3.username, user3.active, user3.sign_in_count);

    // 结构体更新语法
    let user4 = User {
        email: String::from("user4@a.com"),
        username: String::from("user4"),
        active: user1.active,
        sign_in_count: user1.sign_in_count,
    };

    println!("{}, {}, {}, {}", user4.email, user4.username, user4.active, user4.sign_in_count);

    let user5 = User {
        email: String::from("user5@a.com"),
        username: String::from("user5"),
        ..user1
    };

    println!("{}, {}, {}, {}", user5.email, user5.username, user5.active, user5.sign_in_count);

    // 元组结构体
    let _black = Color(0, 0, 0);
    let _origin = Point(0, 0, 0);
}

fn build_user(email: String, username: String) -> User {
    User {
        email: email,
        username: username,
        active: true,
        sign_in_count: 1,
    }
}

fn build_user_simple(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}

