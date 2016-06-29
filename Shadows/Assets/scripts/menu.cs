using UnityEngine;
using System.Collections;

public class menu : MonoBehaviour {

	public static menu save;

	public GUISkin skin;

	public string[] levelname;
	public int[] levelstate;


	private int mode = 0;
	// Use this for initialization

	void Awake () {
		if (save == null)
			save = this;
	}
	void Start () {
		for (int i = 0; i < levelstate.Length; i++) {
			if (!PlayerPrefs.HasKey (levelname[i]))
				PlayerPrefs.SetInt (levelname[i], levelstate[i]);
			else
				levelstate[i] = PlayerPrefs.GetInt (levelname[i]);
		}
		PlayerPrefs.Save ();
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void OnGUI () {
		GUI.skin = skin;
		if (mode == 0) {
			if (GUI.Button (new Rect (Screen.width / 2 - 50, Screen.height / 2 - 60, 100, 60), "Normal mode"))
				mode = 1;
			if (GUI.Button (new Rect (Screen.width / 2 - 50, Screen.height / 2 + 30, 100, 60), "Test mode"))
				mode = 2;
			if (GUI.Button (new Rect (6, 5, 110, 35), "delete save"))
			{
				PlayerPrefs.DeleteAll ();
				Application.LoadLevel("menu");
			}
		} else if (mode == 2) {
			for (int i = 0; i < levelstate.Length; i++) {
				if (GUI.Button (new Rect (Screen.width / 2 - 300 + 100 * i, Screen.height / 2 - 30, 60, 40), levelname[i]))
					Application.LoadLevel(levelname[i]);
			}
		} else if (mode == 1) {
			for (int i = 0; i < levelstate.Length; i++) {
				if (levelstate[i] == 0)
					GUI.Box (new Rect (Screen.width / 2 - 300 + 100 * i, Screen.height / 2 - 30, 80, 50),levelname[i]);
				else if (levelstate[i] == 1){
					if (GUI.Button (new Rect (Screen.width / 2 - 300 + 100 * i, Screen.height / 2 - 30, 80, 50), levelname[i]))
						Application.LoadLevel(levelname[i]);
				}
				else {
					GUI.Box (new Rect (Screen.width / 2 - 300 + 100 * i, Screen.height / 2 - 30, 80, 50), "");
					if (GUI.Button (new Rect (Screen.width / 2 - 300 + 100 * i, Screen.height / 2 - 30, 80, 50), levelname[i]))
						Application.LoadLevel(levelname[i]);
				}
			}
		}
	}
}
