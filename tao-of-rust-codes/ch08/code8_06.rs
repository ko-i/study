fn main() {
    let mut a = String::from("fooå");

    println!("{:p}", a.as_ptr());
    println!("{:p}", &a);

    println!("{:?}", a.len());

    a.reserve(10);
    println!("{:?}", a.capacity());
}