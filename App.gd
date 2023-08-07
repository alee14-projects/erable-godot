extends Control

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var audioURL
var audioFile = File.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	print("Erable is ready")

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _on_PlayButton_pressed():
	if !audioURL == null:
		$AudioStreamPlayer.play()
		print("Now playing " + audioURL)
	else:
		print("No music detected")
	
func _on_StopButton_pressed():
	pass # Replace with function body.


func _on_BrowseButton_pressed():
	print("Opening file dialog")
#	$FileDialog.filters
	$FileDialog.popup_centered()

func _on_FileDialog_file_selected(path):
	audioFile.open(path, File.READ).get_as_text().close()
	$AudioStreamPlayer.stream = load(audioFile)
	

func _on_AudioStreamPlayer_finished():
	print("Music has finished playing")


