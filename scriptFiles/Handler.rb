class Handler
  # Handler class

  @result = nil
  
  def handle
    @result = yield
    @result = true if @result == nil
    self.clone
  end
  
  def result
    @result
  end
  
  def close
    @result = nil
    nil
  end
  
end