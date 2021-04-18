pub fn temp() -> i32 {
    return 1;
}

fn main() {
    let x = &temp();

    temp() = *x; // error
}