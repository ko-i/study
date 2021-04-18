fn main() {
    let four: u32 = "4".parse().unwrap();
    println!("{:?}", four);

    let four = "4".parse::<u32>();
    println!("{:?}", four);
}