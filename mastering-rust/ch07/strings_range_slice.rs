fn main() {
    let my_str = String::from("String are cool");
    println!("{}", &my_str[1..3]);
    let first_three = &my_str[0..3];
    println!("{:?}", first_three);
}