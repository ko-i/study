fn main() {
    let x = 42;
    let y = Box::new(5);
    println!("{:p}", y);

    let x2 = x;
    let y2 = y;
    // let y = Box::new(2);
    // println!("{:p}", y);
}