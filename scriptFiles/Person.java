class Person {
	
	/*
		Class: Person
		Public methods: 11
		Private/Protected method: 5/1
		Using: [String,int,boolean]
		Class from: m.k@mk16.de
		Download class: http://test.mk16.de/scriptFiles/
	*/
	
	// New String for name and language
	// New status for type
	// New int for age
	private String firstname = "";
	private String lastname = "";
	private int age = 0;
	private status type = status.life;
	private String language = "";
	
	// Set enum status [life,dead]
	protected static enum status {
		life,dead
	}
	
	// Public Person methods
	public Person(String name, int NewAge) {
		SetName(name);
		age = NewAge;
	}
	
	public Person(String name) {
		SetName(name);
	}
	
	public Person() {
		SetName("Mark Mustermann");
	}
	
	// Set/Get name
	public void SetName(String name) {
		String[] names = name.split(" ");
		firstname = names[0];
		lastname = names[1];
	}
	
	public String GetName() {
		return firstname + " " + lastname;
	}
	
	// Set/Get age
	public void SetNewAge(int NewAge) {
		age = NewAge;
	}
	
	public int GetAge() {
		return age;
	}
	
	// Age += +1
	public void Birthday() {
		SetNewAge(GetAge() + 1);
	}
	
	// Status = dead
	public void dead() {
		type = status.dead;
		System.out.println(GetName() + " died with the age of " + GetAge() + "!");
	}
	
	// If life
	public boolean IsLife() {
		if(type == status.life)
			return true;
		else
			return false;
	}
	
	// Set/Get language
	public void SetLanguage(String lang) {
		language = lang;
	}
	
	public String GetLanguage() {
		return language;
	}
}