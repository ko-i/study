fn main() {
    let things = ["doorknob", "mushroom", "noodle", "giraffe", "grapefrult"];

    let (living, nonliving): (Vec<&str>, Vec<&str>) = things.iter().partition(|name| name.as_bytes()[0] & 1 != 0);

    println!("{:?}", living);
    println!("{:?}", nonliving);
}