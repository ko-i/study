enum Void {}

fn main() {
    let res: Result<u32, Void> = Ok(0);
    if let Ok(num) = res {
        println!("{:?}", num);
    }
}