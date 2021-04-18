

fn main() {
    let dirs = ["North", "East", "South", "West"];

    let mut spin = dirs.iter().cycle();

    for _ in 1..10 {
        println!("{:?}", spin.next());
    }
}