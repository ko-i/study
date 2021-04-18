fn main() {
    let string = "Hello Rust";
    let ptr = string.as_ptr();
    let len = string.len();

    println!("{:p}", ptr);
    println!("{:?}", len);
}