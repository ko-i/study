fn main() {
    let mut squares = (0..10).map(|i| i * i);

    println!("{:?}", squares.nth(4));
    println!("{:?}", squares.nth(0));

    println!("{:?}", squares.last());
}