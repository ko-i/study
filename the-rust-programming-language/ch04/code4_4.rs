fn main() {
    let s1 = gives_ownership();
    println!("s1: {}", s1);

    let s2 = String::from("hello");
    println!("s2: {}", s2);

    let s3 = takes_and_gives_back(s2);
    println!("s3: {}", s3);
}

fn gives_ownership() -> String {
    let some_string = String::from("hello");

    some_string
}

fn takes_and_gives_back(a_string: String) -> String {
    a_string
}