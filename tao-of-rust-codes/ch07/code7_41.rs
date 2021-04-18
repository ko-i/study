#[derive(Debug)]
pub struct Letter {
    text: String,
}

pub struct Envelope {
    letter: Option<Letter>,
}

pub struct PickupLorryHandle {
    done: bool,
}

impl Letter {
    pub fn new(text: String) -> Self {
        Letter {
            text,
        }
    }
}

impl Envelope {
    pub fn wrap(&mut self, letter: &Letter) {
        self.letter = Some(letter.clone());
    }
}

pub fn buy_prestamped_envelope() -> Envelope {
    Envelope {
        letter: None,
    }
}

impl PickupLorryHandle {
    pub fn pickup(&mut self, envelope: &Envelope) {
        // give letter
    }

    pub fn done(&mut self) {
        self.done = true;

        println!("sent.");
    }
}

pub fn order_pickup() -> PickupLorryHandle {
    PickupLorryHandle {
        done: false,
    }
}

fn main() {
    let letter = Letter::new(String::from("Dear RustFest"));

    let mut envelope = buy_prestamped_envelope();
    envelope.warp(&letter);

    let mut lorry = order_pickup();
    lorry.pickup(&envelope);
    lorry.done();
}