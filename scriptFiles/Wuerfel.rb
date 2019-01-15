class Wuerfel

  attr_reader :augenzahl
  @augenzahl = nil
  @groesze = 6
  
  def initialize groesze=6
    srand Random.new_seed
    @groesze = groesze
  end
  
  def wuerfeln
    @augenzahl = rand 1..@groesze
  end
  
end