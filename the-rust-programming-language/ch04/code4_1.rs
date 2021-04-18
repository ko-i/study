fn main() {
    let _s = "hello";

    let mut s = String::from("hello");
    println!("{}", s);

    s.push_str(", world!");
    println!("{:?}", s);
}