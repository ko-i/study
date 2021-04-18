struct Appellation {
    name: String,
    nicknames: Vec<String>,
}

impl Drop for Appellation {
    fn drop(&mut self) {
        print!("Dropping {}", self.name);

        if !self.nicknames.is_empty() {
            print!(" (AKA {})", self.nicknames.join(", "));
        }

        println!("");
    }
}

fn main() {
    let mut a = Appellation {
        name: "Zeus".to_string(),
        nicknames: vec!["cloud collector".to_string(), "king of god".to_string()],
    };

    println!("Before assignment");

    a = Appellation {
        name: "Hera".to_string(),
        nicknames: vec![],
    };

    let p;
    {
        let q = Appellation {
            name: "Cardamine hirsuta".to_string(),
            nicknames: vec!["shotweed".to_string(), "bittercress".to_string()],
        };

        if true {
            p = q;
        }
    }

    println!("Sproing! What was that?");

    println!("at the end of block");
}