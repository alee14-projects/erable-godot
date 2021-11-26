extends Control

# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var audioURL

# Called when the node enters the scene tree for the first time.
func _ready():
	print("Erable is ready")

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass

func _on_PlayButton_pressed():
	print("Now playing music")
	$AudioStreamPlayer.stream = load(audioURL)
	$AudioStreamPlayer.play()

func _on_BrowseButton_pressed():
	print("Opening file dialog")
	$FileDialog.popup_centered()

func _on_FileDialog_file_selected(path):
	print(path)
	audioURL = "file://" + path

func _on_AudioStreamPlayer_finished():
	print("Music has finished playing")
