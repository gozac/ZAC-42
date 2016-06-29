using UnityEngine;
using System.Collections;

public class goodposition1 : MonoBehaviour {
	
	private bool good = false;

	private bool onclick = false;

	public GameObject scoringobject;

	public KeyCode activekey;

	public bool govert = false;

	public Transform axe;

	public float precision = 2;

	public Quaternion goodrotate;
	

	// Use this for initialization
	void Start () {
	
	}

	bool checkpos () {
		if (Mathf.Abs (goodrotate.x - transform.rotation.eulerAngles.x) <= precision && Mathf.Abs (goodrotate.y - transform.rotation.eulerAngles.y) <= precision && Mathf.Abs (goodrotate.z - transform.rotation.eulerAngles.z) <= precision * 2) {
			scoringobject.SendMessage("addscore");
			good = true;
		}
		return true;
	}
	
	void OnMouseDown() {
		if (good == false)
			onclick = true;
	}

	// Update is called once per frame
	void Update () {
		if (onclick && Input.GetKeyUp (KeyCode.Mouse0)) {
			onclick = false;
			checkpos();
		}
		else if (onclick && (Input.GetKey(activekey) || activekey == KeyCode.None)) {
			float h = -10f * Input.GetAxis("Mouse X");
			float v = -10f * Input.GetAxis("Mouse Y");
			transform.RotateAround(axe.position, Vector3.up, h * 20 * Time.deltaTime);
			if (govert)
				transform.RotateAround(axe.position, Vector3.right, v * 20 * Time.deltaTime);
			//transform.Rotate(0, 0, v);
			//axe.Rotate(-h, 0, 0);*/
		}
	}	
}
