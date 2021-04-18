fn main() {
    let n = "1";
    println!("{:?}", n.parse::<i32>());

    let n = "a";
    println!("{:?}", n.parse::<i32>());
}