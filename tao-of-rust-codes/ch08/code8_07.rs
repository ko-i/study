fn main() {
    let string: String = String::new();
    println!("{:?}", string);

    let string: String = String::from("Hello");
    println!("{:?}", string);

    let string: String = String::with_capacity(20);
    println!("{:?}", string);

    let str_: &'static str = "the tao of rust";
    let string: String = str_.chars().filter(|c| !c.is_whitespace()).collect();
    println!("{:?}", string);

    let string: String = str_.to_owned();
    println!("{:?}", string);

    let string: String = str_.to_string();
    let str_: &str = &string[11..15];
    println!("{:?}", str_);
}