fn main() {
    let s = String::from("hello");
    takes_ownership(s);

    let x = 5;
    make_copy(x);
}

fn takes_ownership(some_string: String) {
    println!("{}", some_string);
}

fn make_copy(some_integer: i32) {
    println!("{}", some_integer);
}