fn main() {
    let mut v = String::from("boros");

    println!("{:?}", v.get(0..1));
    println!("{:?}", v.get(3..5));
    println!("{:?}", v.get(1..));

    println!("{:?}", v.get_mut(4..).is_none());
    println!("{:?}", v.is_char_boundary(4));
    println!("{:?}", v.get_mut(..8).is_none());
    println!("{:?}", v.get_mut(..42).is_none());
}