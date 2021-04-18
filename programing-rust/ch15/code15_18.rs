use std::iter::repeat;

fn main() {
    let v: Vec<_> = (0..).zip("ABCD".chars()).collect();

    println!("{:?}", v);

    let endings = vec!["once", "twice", "chicken soup with rice"];

    let rhyme: Vec<_> = repeat("going").zip(endings).collect();
    println!("{:?}", rhyme);
}