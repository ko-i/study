fn main() {
    let x = Box::new("hello");
    let y = x;

    // print!("{:?}", x);
    print!("{:?}", y);
}