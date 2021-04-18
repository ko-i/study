fn main() {
    let x = true;
    let y: bool = false;
    let x = 5;
    if x > 1 {
        println!("x is bigger than 1");
    }

    assert_eq!(5, x as i32);
    assert_eq!(0, y as i32);
}